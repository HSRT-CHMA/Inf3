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
	b : BOOLEAN
	--Value is used in has()-Function
	--s : STRING

feature --Getter root
	get_root : detachable NODE
	do
		Result := root --Result is built-in and used instead of "return"
	end



feature{NONE} -- Insert-Method (duplicates possible)

	insertRec(new_value : INTEGER; used_node : NODE)

		do
			if new_value >= used_node.get_value then
				--Right
				if attached used_node.get_right as checked_right then
					-- Line does the follwing : if used_node.get_right is "attached" (equals to "/= Void")
					-- then a new object with name after "as", here "checked_rigth", is created and can be used because it is proven
					--that it isn't Void
					insertRec(new_value, checked_right)
				else
					-- else if (used_node.get_right = Void)
					create first_node.make(new_value, used_node)
					used_node.set_right(first_node)
				end
			else
				--Left
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
			print("%N Value " + new_value.out + " is added to binary tree")
		end


feature{NONE} -- Has_method Sub (can only be used by this Class)

	has_rec(new_value : INTEGER ; n : NODE) : BOOLEAN
		do
			if new_value.is_equal (n.get_value) then
				Result := true
			end

			if new_value.is_less(n.get_value) then
				if attached n.get_left as checked_left then -- x /= Void -> checked_left
					Result := has_rec(new_value, checked_left)
				end
			end

			if new_value.is_greater_equal (n.get_value) then
				if attached n.get_right as checked_right then
					Result := has_rec(new_value, checked_right)
				end
			end
		end


feature -- "Public" Has-Methode

	has(new_value : INTEGER) : BOOLEAN
		do
			if attached Current.get_root as check_root then
				Result := has_rec(new_value, check_root)
			end
			print("has-Method terminated")
		end




end
