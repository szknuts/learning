import { Navigate, Outlet } from "react-router-dom";
import SideBar from "./components/SideBar";
import { SearchModal } from "./components/SearchModal";
import { useCurrentUserStore } from "./modules/auth/current-user.state";
import { useNoteStore } from "./modules/notes/note.state";
import { useEffect, useState } from "react";
import { noteRepository } from "./modules/notes/note.repository";

const Layout = () => {
  //ログインしてないならsigninに飛ばす
  const { currentUser } = useCurrentUserStore();
  if (currentUser == null) return <Navigate replace to="/signin" />;

  const noteStore = useNoteStore();
  const [isLoading, setIsLoading] = useState(false);

  useEffect(() => {
    fetchNotes();
  }, []);
  const fetchNotes = async () => {
    setIsLoading(true);
    const notes = await noteRepository.find(currentUser!.id);
    if (notes == null) return;
    noteStore.set(notes);
    setIsLoading(false);
  };

  return (
    <div className="h-full flex">
      {!isLoading && <SideBar onSearchButtonClicked={() => {}} />}
      <main className="flex-1 h-full overflow-y-auto">
        <Outlet />
        <SearchModal
          isOpen={false}
          notes={[]}
          onItemSelect={() => {}}
          onKeywordChanged={() => {}}
          onClose={() => {}}
        />
      </main>
    </div>
  );
};

export default Layout;
