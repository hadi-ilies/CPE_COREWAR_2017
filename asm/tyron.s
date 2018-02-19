.name "Tyron"
.comment "just a basic pompes, traction program"

	sti r1, %:hi, %1
hi:	live %123
	ld %0, r3
	zjmp %:hi
