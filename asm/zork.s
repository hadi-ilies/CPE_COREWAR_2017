.name "zork"
.comment "Un champion avec un commentaire, c'est un bon champion."

12:     sti r1, %:live, %1
	and r1 ,%0, r1

live:   live %1
	zjmp %:live
