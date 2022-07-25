address book
	1.) address
		name,
		door no
		Apartment name, block name
		street name
		place
		city
		pincode
		contact
		email
		lptr
		rptr
	2.) functions
		display (display all the addresses, address of a specific person or ppl with the same name)
		addentry (Add a new person and the person's address)
		save (Save all the entries to a file according to lexical order)
		modify (to modify an entry)
		deletee (delete a person's details both in memory and in file)
		deleteall (delete all the entries in the file and clear all the memory)


addentry
	get the details, form a doubly linked list in lexical order according to name
displayall
	Display the entries starting from start pointer to end pointer
save
	To save all the entries in a separate txt file
display
	To display details of a specific person or people with the same name
disp_file
	To display all the entries from the file
modify
	To modify specific details of a specific person
deleteall
	Delete all the data and clear all memory spaces
deletee
	Delete a specific entry by seraching for the name
