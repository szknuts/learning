import { atom, useAtom } from "jotai";
import { Note } from "./note.entity";

const noteAtom = atom<Note[]>([]);

export const useNoteStore = () => {
  const [notes, setNotes] = useAtom(noteAtom);

  const set = (newNotes: Note[]) => {
    setNotes((oldNotes) => {
      const combinceNotes = [...oldNotes, ...newNotes];
      const uniqueNotes: Record<number, Note> = {};
      for (const note of combinceNotes) {
        uniqueNotes[note.id] = note;
      }
      return Object.values(uniqueNotes);
    });
  };

  return {
    getAll: () => notes,
    set,
  };
};
