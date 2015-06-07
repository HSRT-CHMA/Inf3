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
		end

feature --Access

	tree1 : BINARYTREE[STRING]
	-- binary tree for testing
--	tree2 : AVLTREE[INTEGER]
	-- avl tree for testing
--	tree3 : AVLTREE[STRING]
	-- avl tree for testing
	tree4 : BINARYTREE[INTEGER]
	-- binary tree for testing


feature -- Method creates 2 trees for testing and fills them with values

	test_insert
	do
		print("%N%N--test_insert--%N%N")
		create tree1.make("fjsfsd")
--		create tree2.make(101)
--		create tree3.make("wesg")
		create tree4.make(101)

        -- Insert tree1
		tree1.insert("wnef")
		tree1.insert("sdfsdf")
		tree1.insert("fjsfsd")
		tree1.insert("sdjfirwog")
		tree1.insert("sfiowjf")
		-- Insert tree2
--		tree2.insert(90)
--		tree2.insert(104)
--		tree2.insert(140)
--		tree2.insert(5)
--		tree2.insert(95)
		-- Insert tree3
--		tree3.insert("wesgd")
--		tree3.insert("sfag")
--		tree3.insert("sdfga")
--		tree3.insert("sfwgsg")
--		tree3.insert("sdfarg")
		-- Insert tree4
		tree4.insert(90)
		tree4.insert(104)
		tree4.insert(90)
		tree4.insert(5)
		tree4.insert(95)
		ensure
			valid_tree : tree1 /= Void
--			valid_tree : tree2 /= Void
--			valid_tree : tree3 /= Void
			valid_tree : tree4 /= Void

	end

feature -- Method for testing the has-Method

	test_has
	do
		print("%N%N--test_has--%N%N")
		-- Tests on tree1
		print(tree1.has("aerbgierhg")) --should be False
		print("%N")
		print(tree1.has("fargsehh")) --should be False
		print("%N")
		print(tree1.has("wenf")) --should be True
		print("%N")
		print(tree1.has("wenf").out) --should be True
		-- Tests on tree2
--		print(tree2.has(4)) --should be False
--		print("%N")
--		print(tree2.has(1000)) --should be False
--		print("%N")
--		print(tree2.has(5)) --should be True
--		print("%N")
--		print(tree2.has(101).out) --should be True
--		print("%N%N")
		-- Tests on tree3
--		print(tree3.has("agaerga")) --should be False
--		print("%N")
--		print(tree3.has("sadfasg")) --should be False
--		print("%N")
--		print(tree3.has("wesg")) --should be True
--		print("%N")
--		print(tree3.has("wesg").out) --should be True
		-- Tests on tree4
		print(tree4.has(4)) --should be False
		print("%N")
		print(tree4.has(1000)) --should be False
		print("%N")
		print(tree4.has(5)) --should be True
		print("%N")
		print(tree4.has(101).out) --should be True
	end

feature -- Methode for testing the delete-Method, prints results on the console

	test_delete
 	do
 		print("%N%N--test_delete--%N%N")
 		tree1.delete ("sfiowjf") -- Possible
 		print("%N")
 		tree1.delete ("wnef") -- Possible
 		print("%N")
 		tree1.delete ("haureaguay") --Not possible because it does not exist
 		print("%N")
 		tree1.delete ("fjsfsd") -- Not possible because root node
 		-- tree2
-- 		tree2.delete (95) -- Possible
-- 		print("%N")
-- 		tree2.delete (140) -- Possible
-- 		print("%N")
-- 		tree2.delete (188989) --Not possible because it does not exist
-- 		print("%N")
-- 		tree2.delete (101) -- Not possible because root node
 		-- tree3
-- 		tree3.delete ("sfag") -- Possible
-- 		print("%N")
-- 		tree3.delete ("sdfga") -- Possible
-- 		print("%N")
-- 		tree3.delete ("awhfbaelrgbsilearg") --Not possible because it does not exist
-- 		print("%N")
-- 		tree3.delete ("wesg") -- Not possible because root node
 		-- tree4
 		tree4.delete (95) -- Possible
 		print("%N")
 		tree4.delete (140) -- Possible
 		print("%N")
 		tree4.delete (188989) --Not possible because it does not exist
 		print("%N")
 		tree4.delete (101) -- Not possible because root node
	end

invariant
	valid_tree : tree1 /= Void
--	valid_tree : tree2 /= Void
--	valid_tree : tree3 /= Void
	valid_tree : tree4 /= Void

end
