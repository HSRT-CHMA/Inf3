note
	description : "exercise3 Main Application"
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
			test_insert
			test_has
			test_delete
			test_hight
		end

feature --Access

	tree1 : BINARYTREE[INTEGER]
	-- binary tree for testing
	tree2 : AVLTREE[INTEGER]
	-- avl tree for testing
	tree3 : AVLTREE[CHARACTER]
	-- avl tree for testing
	tree4 : BINARYTREE[CHARACTER]
	-- binary tree for testing
	tree5 : AVLTREE[STRING]
	-- avl tree for testing
	tree6 : BINARYTREE[STRING]
	-- binary tree for testing
	tree7 : AVLTREE[REAL]
	-- avl tree for testing
	tree8 : BINARYTREE[REAL]
	-- binary tree for testing

feature -- Method creates 8 trees for testing and fills them with values

	test_insert
	do
		print("%N%N--test_insert--%N%N")
		create tree1.make(99)
		create tree2.make(10)
		create tree3.make('a')
		create tree4.make('f')
		create tree5.make("Hi")
		create tree6.make("JO")
		create tree7.make(12.5)
		create tree8.make(12.8)
        -- Insert tree1
		tree1.insert(90)
		tree1.insert(101)
		tree1.insert(140)
		tree1.insert(5)
		tree1.insert(95)
		-- Insert tree2
		tree2.insert (15)
		tree2.insert (12)
		tree2.insert (74)
		tree2.insert (93)
		tree2.insert (8)
		-- Insert tree3

		-- Insert tree4

		ensure
			valid_tree : tree1 /= Void
			valid_tree : tree2 /= Void
			valid_tree : tree3 /= Void
			valid_tree : tree4 /= Void
			valid_tree : tree5 /= Void
			valid_tree : tree6 /= Void
			valid_tree : tree7 /= Void
			valid_tree : tree8 /= Void
	end

feature -- Method for testing the has-Method

	test_has
	do
		print("%N%N--test_has--%N%N")
		-- Tests on tree1
		print(tree1.has(4)) --should be False
		print("%N")
		print(tree1.has(1000)) --should be False
		print("%N")
		print(tree1.has(5)) --should be True
		print("%N")
		print(tree1.has(101).out) --should be True
		--Tests on tree2
		print("%N%N")
		print(tree2.has(93)) --should be True
		print("%N")
		print(tree2.has(14)) --should be False
		print("%N")
		print(tree2.has(9)) --should be False
		print("%N")
		print(tree2.has(15)) --should be True
	end

feature -- Methode for testing the delete-Method, prints results on the console

	test_delete
 	do
 		print("%N%N--test_delete--%N%N")
 		tree2.delete (15) -- Possible
 		print("%N")
 		tree1.delete (95) -- Possible
 		print("%N")
 		tree1.delete (140) -- Possible
 		print("%N")
 		tree1.delete (188989) --Not possible because it does not exist
 		print("%N")
 		tree2.delete (1) --Not possible because it does not exist
 		print("%N")
 		tree1.delete (99) -- Not possible because root node
	end

feature -- Method for testing the hight-Method, prints result on the console	

	test_hight
	do
		print("%N%N--test_hight--%N%N")

	end

invariant
	valid_tree : tree1 /= Void
	valid_tree : tree2 /= Void

end
