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
			-- make-routine of class APPLICATION, serves as "main"
		do
			print ("Hello, this is a programm to create binary trees !%N")
			test_insert
			--test_has
			--test_delete
			--test_max_sum
			test_gps
		end

feature --Access

	tree1 : BINARYTREE
	-- binary tree for testing
	tree2 : BINARYTREE
	-- binary tree for testing
	gps1 : GPS
	-- general problem solver for testing

feature -- Method for testing the GPS and its sub-classes

	test_gps
	do
		create gps1.make(tree1)
		
	end


feature -- Method creates 2 trees for testing and fills them with values

	test_insert
	do
		create tree1.make(99)
		create tree2.make(10)
        -- Insert tree1
		tree1.insert(90)
		tree1.insert(101)
		tree1.insert(101)
		tree1.insert(5)
		tree1.insert(95)
		-- Insert tree2
		tree2.insert (15)
		tree2.insert (80)
		tree2.insert (-74)
		tree2.insert (7)
	end

feature -- Method for testing the has-Method

	test_has
	do
		-- Tests on tree1
		print("%N")
		print(tree1.has(4)) --should be False
		print("%N")
		print(tree1.has(1000)) --should be False
		print("%N")
		print(tree1.has(5)) --should be True
		print("%N")
		print(tree1.has(101).out) --should be True

		--Tests on tree2
		print("%N%N")
		print(tree2.has(80)) --should be False
		print("%N")
		print(tree2.has(14)) --should be False
		print("%N")
		print(tree2.has(9)) --should be True
		print("%N")
		print(tree2.has(15)) --should be True
	end

feature -- Methode for testing the delete-Method

	test_delete
 	do
        -- Tests on delete()
		tree2.delete(1) --should be false
		print("%N")
		tree1.delete(99) -- should be true
		print("%N")
		print("Is 99 in tree ? " + tree1.has (99).out) -- shoulb be false
		print("%N")
		tree2.delete(8) --should be true
		print("%N")
		print("Is 8 in tree ? " + tree2.has (8).out) --should be false
		print("%N")
		tree2.delete(1) --should be false
	end

feature -- Methode for testing the max and sum -Methods

	test_max_sum
	do
		--print("%NTest on sum %N")
		--print(tree1.sum.out)
		--print("%NTest 2 on sum %N")
		--print(tree2.sum.out)
		--print("%N Test on max %N")
		--print(tree1.max.out)
		--print("%NTest 2 on max %N")
		--print(tree2.max.out)
	end

end
