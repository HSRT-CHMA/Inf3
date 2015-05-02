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
		end

feature --Access

	first_node : detachable NODE
	-- Gets created by a new tree, used in insert()- Method
	root : detachable NODE
	-- Becomes the root of the new tree
	found : BOOLEAN
	--Value is used in has()-Function
	res_node : detachable NODE
	-- Result-Node to be used in has()-Method
	delete_node : detachable NODE
	-- Node to be used in delete() and delete_rec
	tmp_node : detachable NODE
	--Node to be used in delete_rec()

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
				if attached used_node.get_left as checked_left then -- x /= Void
					insertRec(new_value, checked_left)
				else
					create first_node.make(new_value, used_node) -- x = Void
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


feature{NONE} -- Delete-Method Sub

	deleteRec(new_value : INTEGER; used_node : NODE)
		require
			correct_node : new_value = used_node.get_value
			valid_node : used_node /= Void
		do
			if attached Current.get_root as valid_root then

				-- Leaf
				if used_node.get_left = Void and used_node.get_right = Void then
					print("Leaf")
					if attached used_node.get_parent as checked_parent then -- x /= Void
						checked_parent.set_right(Void)
					else
						root := Void
					end
				end

				--Right child
				if used_node.get_left = Void and used_node.get_right /= Void then
					print("One rigth child")
					if attached used_node.get_parent as checked_parent then -- x /= Void
						checked_parent.set_right(used_node.get_right)
					else
						root := used_node.get_right
					end
				end

				--Left child
				if used_node.get_left /= Void and used_node.get_right = Void then
					print("One left child")
					if attached used_node.get_parent as checked_parent then -- x /= Void
						checked_parent.set_right(used_node.get_left)
					else
						root := used_node.get_left
					end
				end

				--Right and left child
				if attached used_node.get_left as check_left and attached used_node.get_right as check_right then
					print("Two children")
					tmp_node := get_smallest(check_right)
					if attached tmp_node as check_tmp_node then
						delete(check_tmp_node.get_value)
						if attached used_node.get_parent as checked_parent then -- x /= Void
							check_tmp_node.set_left (check_left)
							check_tmp_node.set_right (check_right)
							checked_parent.set_right (check_tmp_node)
						else
							check_tmp_node.set_left (valid_root.get_left)
							check_tmp_node.set_right (valid_root.get_right)
							root := check_tmp_node
						end
					end
				end
			end
			--ensure
			--value_is_deleted : has(new_value) = false
		end

feature -- A helping method for deleteRec

	get_smallest(start : NODE) : NODE
		Local
			node : NODE
		do
			from
				node := start
			until
				node.get_left = Void
			loop
				if attached node.get_left as ok_left then
					node := ok_left
				end
			end
			Result := node
		end


feature --"Public" Delete-Method

	delete(new_value : INTEGER)
		do
			if attached Current.get_root as check_root then
				delete_node := has_rec(new_value, check_root)
			end

			if attached delete_node as check_delete_node then
			-- has_rec returnt a Node
				print("Value can be deleted")
				deleteRec(new_value, check_delete_node)
			else
			-- has_rec returnt Void
				print("Value does not exist in the given tree")
			end
		end

feature -- "public" has()

	has(new_value : INTEGER): BOOLEAN
	do
		if attached Current.get_root as check_root then
			res_node := has_rec(new_value, check_root)
		end

		if res_node = Void then
			-- if has_rec returns a Void-Object, the value has not been found
			found := false
		else
			-- if has_rec returns a not-Void Object, the value has been found
			found := true
		end
		Result := found
	end

feature{NONE} -- "private" has(), indicated by Exportation to class NONE

	has_rec(new_value : INTEGER ; used_node : NODE) : detachable NODE
	do
		if new_value = used_node.get_value then --Value has been found, return Node
			Result := used_node
		end

		--Search on the left side
		if new_value < used_node.get_value then
			if attached used_node.get_left as check_left then -- x /= Void, continue with check_
				Result := has_rec(new_value, check_left)
			else -- x = Void -> No more Nodes -> Value does not exist
				Result := Void
			end
		end

		--Search on the right side
		if new_value > used_node.get_value then --Be careful here
			if attached used_node.get_right as check_right then
				Result := has_rec(new_value, check_right)
			else
				Result := Void
			end
		end
	end

end --End of class
