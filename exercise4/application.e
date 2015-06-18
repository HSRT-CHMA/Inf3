note
	description : "exercise4 Main Application"
	date        : "$Date$"
	revision    : "$Revision$"

class
	APPLICATION
	--root-class of the project

inherit
	ARGUMENTS

create
	make

feature {NONE} -- Initialization; containts different testing units

	make
			-- make-routine of class APPLICATION, serves as "main"
		do
			print ("Hello, this is a programm to create & test generic trees !%N")
			create ra.make
			create tree_string.make ("root-node")
			t := ra.get_ra_double (0, 20)
			create tree_d.make(t)

			-- Test on tree with double
			create test_d.make (tree_d)
			test_d.tree_init (-20, 20, 10)
			-- 10 elements in the tree


			-- Test in tree with string
			create test_st.make (tree_string)
			test_st.tree_init (-20, 20, 10)

		end

feature --Access

	tree_string : BINARYTREE[STRING]
	--binary tree for testing
	tree_d : BINARYTREE[DOUBLE]
	-- binary tree for testing
	ra : RANDOMGENERATOR
	t : DOUBLE
	test_d : TEST_DOUBLE
	test_st : TEST_STRING


end
