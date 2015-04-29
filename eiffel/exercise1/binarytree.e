note
	description: "Summary description for {BINARYTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BINARYTREE

create
	make

feature {NONE} -- Initialization

	make(tree_value : INTEGER)
			-- Initialization for `Current'.
		do
			print("%N New Tree !!")
			create root.make(tree_value, Void)
			--root := first_node
		end

feature --Access

	first_node : detachable NODE
	-- Gets created by a new tree
	root : detachable NODE
	-- Becomes the root of the new tree

feature --Getter root
	get_root : detachable NODE
	do
		Result := root --Result is built-in and used instead of "return"
	end



feature{NONE} -- Insert-Method

	insertRec(new_value : INTEGER; used_node : NODE)
		do
			if new_value >= used_node.get_value then
				--Rechts
				if attached used_node.get_right as checked_right then
					insertRec(new_value, checked_right)
				else -- used_node = Void
					create first_node.make(new_value, used_node)
					used_node.set_right(first_node)
				end
			else
				--Links
				if attached used_node.get_left as checked_left then
					insertRec(new_value, checked_left)
				else
					create first_node.make(new_value, used_node)
					used_node.set_left(first_node)
				end
			end
		end

feature -- Insert-Methode Sub

	insert(new_value : INTEGER)
		do
			if attached Current.get_root as checked_root then
				insertRec(new_value , checked_root)
			end
			print("Value " + new_value.out + " is added to binary tree")
		end

end
