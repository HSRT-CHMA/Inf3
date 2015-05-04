note
	description : "exersice-02 application root class"
	date        : "$Date$"
	revision    : "$Revision$"

class
	APPLICATION

inherit
	ARGUMENTS

create
	make

feature {NONE} -- Initialization

	make
			-- Run application.
		do
			--| Add your code here
			print ("Welcome !  This is a programm to solve problems on binary trees!%N")
			create tree.make
			create my_gps.make(tree)


		end

feature --Access

	tree : BINARYTREE
	my_gps : GPS

end
