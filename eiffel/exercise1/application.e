note
	description : "exercise_01 application root class"
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
			print ("Hello, this is a programm to create binary trees !%N")
			create tree1.make(99)
			create tree2.make(122)
		end

feature --Access

	tree1 : BINARYTREE
	tree2 : BINARYTREE
end
