import { supabase } from "@/lib/supabase";

export const noteRepository = {
  async create(userId: string, params: { title?: string; parentID?: string }) {
    const { data, error } = await supabase
      .from("notes")
      .insert([
        {
          user_id: userId,
          title: params.title,
          parent_document: params.parentID,
        },
      ])
      .select()
      .single();
    if (error != null) throw new Error(error.message);
    return data;
  },
  async find(userId: string, parentDocumentID?: number) {
    const query = supabase
      .from("notes")
      .select()
      .eq("user_id", userId)
      .order("created_at", { ascending: false });

    const { data } =
      parentDocumentID != null
        ? await query.eq("parent_document", parentDocumentID)
        : await query.is("parent_document", null);
    return data;
  },
};
