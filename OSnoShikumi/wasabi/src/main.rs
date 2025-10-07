#![no_std]
#![no_main]

#[no_mangle] // 関数の名前をコンパイル時に変更しない と指示するための属性
             //FFI(Foreign Function Interface)(多言語からrustの関数を呼ぶとき)のとき使う
             //標準ライブラリを使わない環境(no_std)のとき、プログラムの開始地点をリンカに伝える際に必要
fn efi_main() {
    loop {}
}

//パニックハンドラ：パニック(回復不可能なエラー)に陥ったときに実行する
use core::panic::PanicInfo;
#[panic_handler] //パニックハンドラであるという属性。唯一
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

///UEIFアプリケーションのmain関数(エントリーポイント)
///
/// * '_image_handle' - UEFIファームウェア自身の情報
/// * 'efi_system_table' - EFI System Tableのアドレス
#[no_mangle] //この関数を見つけられるように
fn efi_main(_image_handle: EfiHandle, efi_system_table: &EFISystemTable) {
    let eif_graphics_output_protocol = locate_graphic_protocol(efi_system_table).unwrap();
    let vram_addr = eif_graphics_output_protocol.mode.frame_buffer_base;
    let vram_byte_size = eif_graphics_output_protocol.mode.frame_buffer_size;
    let vram = unsafe {
        // *mut u32→ 1pxを4バイトの色情報として扱うため
        slice::form_raw_parts_mut(vram_addr as *mut u32, vram_byte_size / size_of::<u32>())
    };
    for e in vram {
        *e = 0xffffff; //白(ffffff)で塗りつぶす
    }
    loop {}
}

/*
UEFI仕様で定められているC言語の EFI_BOOT_SERVICES テーブルの1部をRustで表現したもの
OSのローダーが、ファームウェアが提供する機能(プロトコル検索、メモリ確保など)を利用するときに使う
 */
#[repr(C)] //メモリ配置を最適化せずに、C言語と同じ形式にする
struct EfBootServiceseTable {
    _reserved0: [u64; 40], // u64(8B)*40=320 の領域を確保
    locate_protocol: extern "win64" fn(
        //UEFI仕様が windows 64-bitの呼び出し規約を使用しているので合わせている
        protocol: *const EfiGuid,
        registration: *const EfiVoid,
        interface: *mut *mut EfiVoid,
    ) -> EfiStatus,
}
/*
コンパイル時アサーション
offset_of(...)：第1引数の先頭から、第2引数の先頭までの距離(オフセット)をバイト単位で計算
assert!(...)：計算したオフセットが320であるかコンパイル時にチェック。falseならコンパイルエラー
*/
const _: assert!(offset_of!(EfiBootServicesTable, locate_protocol) == 320);

#[repr(C)]
struct EFISystemTable {
    _reserved0: [u64; 12],
    pub boot_services: &'static EfiBootServicesTable,
}
const _: assert!(offset_of!(EFISystemTable, boot_services) = 96);

const EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID: EfiGuid = EfiGuid {
    data0: 0x9042a9de,
    data1: 0x23dc,
    data2: 0x4a38,
    data3: [0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a],
};

#[repr(C)]
#[derive(Clone, Copy, PartialEq, Eq, Debug)]
struct EfiGuid {
    pub data0: u32,
    pub data: u16,
    pub data: u16,
    pub data: [u8; 8],
}
