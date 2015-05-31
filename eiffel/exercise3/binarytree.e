note
	description: "Summary description for {BINARYTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BINARYTREE
	-- This class organises the binary tree and provides important methods

inherit
	GENERIC_TREE
	
create
	make

feature {NONE} -- Initialization / Constructor ; gets the value that serves as root-value

	make(tree_value : INTEGER)
		do
			print("%N A new BinaryTree has been created")
			create root.make(tree_value, Void)
			act_root_value := tree_value
		end

feature --Access

	root : detachable NODE
	-- Becomes the root of the new tree; can be void
	--not_void_root : NODE
	-- A not void version of root
	first_node : detachable NODE
	-- Gets created by a new tree, used in insert()- Method
	res_node : detachable NODE
	-- Result-Node to be used in has()-Method
	delete_node : detachable NODE
	-- Node to be used in delete()
	act_root_value : INTEGER


feature --public Getter for root
	get_root : detachable NODE
	do
		Result := root
		--Result is built-in and used instead of "return"
		ensure
			correct_result : Result = root
	end

	--get_not_void_root : NODE
	--do
		--if attached root as checked_root then
			--Result := checked_root
		--end
	--end


feature{BINARYTREE} -- private Insert-Method (duplicates possible) which add the used_node with the given value to its tree
					-- Nodes are added as following : left child is smaller than its root, root ist smaller or equal than its right child

	insertRec(new_value : INTEGER; used_node : NODE)

		do
			if new_value >= used_node.get_value then
				--Add node on the Right Side
				if attached used_node.get_right as checked_right then
					-- Line does the follwing : if used_node.get_right is "attached" (equals to "/= Void")
					-- then a new object with name after "as", here "checked_rigth", is created and can be used because it is proven
					-- that it isn't Void
					insertRec(new_value, checked_right)
				else
					-- else if (used_node.get_right = Void)
					create first_node.make(new_value, used_node)
					used_node.set_right(first_node)
				end
			else
				--Add node on the Left side
				if attached used_node.get_left as checked_left then -- to be used like (x /= Void)
					insertRec(new_value, checked_left)
				else
					create first_node.make(new_value, used_node) -- to be used like (x = Void)
					used_node.set_left(first_node)
				end
			end
			ensure
				value_is_in_tree : current.has (new_value)
		end


feature -- public Insert-Methode; redirects to insert_rec, and prints a message on the console

	insert(new_value : INTEGER)
		do
			if attached Current.get_root as checked_root then
				insertRec(new_value , checked_root)
			end
			print("%N The value " + new_value.out + " has been added to tree")
			ensure
				tree_has_value : current.has (new_value)
		end


feature{BINARYTREE} -- Delete-Method to delete one Node with given value in tree;
					-- Method uses local variables
					--smallNode is used to save the node with smallest value in tree
					--tmpNode is used to save a Node's information while deleting

	deleteRec(new_value : INTEGER; used_node : NODE)
		require
			correct_node : new_value = used_node.get_value
			valid_node : used_node /= Void
		Local
			smallNode : detachable NODE
			tmpNode : detachable NODE
		do
			if attached Current.get_root as valid_root then
				-- Leaf
				if used_node.get_left = Void and used_node.get_right = Void then
					print("%NNode is a Leaf%N")
					if attached used_node.get_parent as checked_parent then -- x /= Void
						checked_parent.set_right(Void)
					end

				--Right child
				elseif used_node.get_left = Void and used_node.get_right /= Void then
					print("%NNode has one rigth child%N")
					if attached used_node.get_parent as checked_parent then -- x /= Void
						checked_parent.set_right(used_node.get_right)
					else
						root := used_node.get_right
					end

				--Left child
				elseif used_node.get_left /= Void and used_node.get_right = Void then
					print("%NNode has one left child%N")
					if attached used_node.get_parent as checked_parent then -- x /= Void
						checked_parent.set_right(used_node.get_left)
					else
						root := used_node.get_left
					end
				--Right and left child
				elseif attached used_node.get_left as check_left and attached used_node.get_right as check_right then
					print("%NNode has two children%N")
					-- Search for smallest sucessor
                	if(check_right.get_value < check_left.get_value) then
                		smallNode := used_node.get_left
                	elseif(check_right.get_value > check_left.get_value)then
                		smallNode := used_node.get_right
                	else
                		smallNode := used_node
                	end

                	if (tmpNode = used_node) then --Put value in place of Node to be deleted --> "removed"
                		if attached used_node.get_right as ok_right2 then
								used_node.set_value(ok_right2.get_value)
						end
						-- Set the following tree under the new node in place
                    	tmpNode := used_node.get_right

                 		if attached used_node.get_left as ok_left2 then
							used_node.set_right(ok_left2.get_right)
						end

                  	else
                  		if attached used_node.get_left as ok_left3 then
							used_node.set_value(ok_left3.get_value)
						end
					end
				end
			end
		end


feature --"Public" Delete-Method, redirects to deleteRec and prints result of it on the console; prohibites to delete the root
		-- Method uses a local variable : root_value containts the int-value of the tree-root

	delete(new_value : INTEGER)
		Local
			root_value : INTEGER
		do
			if attached Current.get_root as check_root then
				delete_node := has_rec(new_value, check_root)
				root_value := check_root.get_value
			end

			if not root_value.is_equal (new_value) then
				if attached delete_node as check_delete_node then
			-- has_rec returnt a Node
				--print("Value can be deleted")
				deleteRec(new_value, check_delete_node)
				print("Value has been deleted")
				else
			-- has_rec returnt Void
				print("Value does not exist in the given tree")
				end
			else
				print("You try to delete the root of this tree, this is not allowed")
			end
			--ensure
				--root_not_deleted : has_rec(root_value, root)

		end

feature -- public Method to check if a value is in a tree; returns true if value is found

	has(new_value : INTEGER): BOOLEAN
	require
		valid_value : new_value.abs >= 0
	Local
		found : BOOLEAN
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
		ensure
			valid_result : Result = true or Result = false
	end

feature{BINARYTREE} -- "private" has(), indicated by Exportation to class NONE, searches for the given Node in a tree
					-- if Node has been found, result is the found Node with the given value
					-- if a Node with given value can not be found , result is Void

	has_rec(new_value : INTEGER ; used_node : NODE) : detachable NODE
	require
		valid_value : new_value.abs >= 0
		valid_node : used_node /= Void
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



invariant
	valid_root_value : act_root_value.abs >= 0

end --End of class
