note
	description: "Summary description for {GENERIC_TREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class GENERICTREE[G->COMPARABLE]
-- Generic Tree Class giving methods to other generic trees
inherit
	MAINTREE[G]
	redefine insert, delete, has end

feature --Access

	root : detachable NODE[G]
	-- Becomes the root of the new tree; can be void
	first_node : detachable NODE[G]
	-- Gets created by a new tree, used in insert()- Method
	res_node : detachable NODE[G]
	-- Result-Node to be used in has()-Method
	delete_node : detachable NODE[G]
	-- Node to be used in delete()
	root_value : detachable G
	-- root value

feature --public Getter for root
	get_root : detachable NODE[G]
	do
		Result := root
		--Result is built-in and used instead of "return"
		ensure
			correct_result : Result = root
	end

feature{GENERICTREE} -- private Insert-Method (duplicates possible) which add the used_node with the given value to its tree
					 -- Nodes are added as following : left child is smaller than its root, root ist smaller or equal than its right child

	insertRec(new_value : G ; used_node : NODE[G])

		do
			if attached used_node as checked_un then
				if new_value <= checked_un.get_value then  -- Caution
					--Add node on the Right Side
					if attached checked_un.get_right as checked_right then
						-- Line does the follwing : if used_node.get_right is "attached" (equals to "/= Void")
						-- then a new object with name after "as", here "checked_rigth", is created and can be used because it is proven
						-- that it isn't Void
						insertRec(new_value, checked_right)
					else
						-- else if (used_node.get_right = Void)
						create first_node.make(new_value, checked_un)
						checked_un.set_right(first_node)
					end
				else
					--Add node on the Left side
					if attached checked_un.get_left as checked_left then -- to be used like (x /= Void)
						insertRec(new_value, checked_left)
					else
						create first_node.make(new_value, checked_un) -- to be used like (x = Void)
						checked_un.set_left(first_node)
					end
				end
			end
		end


feature -- public Insert-Methode; redirects to insert_rec, and prints a message on the console

	insert(new_value : G)
		do
			if attached Current.get_root as checked_root then
				insertRec(new_value , checked_root)
			end
--			ensure then
--				tree_has_value : has (new_value)
		end


feature{GENERICTREE} -- Delete-Method to delete one Node with given value in tree;
					-- Method uses local variables
					--smallNode is used to save the node with smallest value in tree
					--tmpNode is used to save a Node's information while deleting

	deleteRec(new_value : G; used_node : NODE[G])
		require else
			correct_node : new_value = used_node.get_value
			valid_node : used_node /= Void
		Local
			smallNode : detachable NODE[G]
			tmpNode : detachable NODE[G]
		do
			if attached Current.get_root as checked_root then
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
					-- Search for smallest node
                	if(check_right.get_value.is_less(check_left.get_value)) then
                		smallNode := used_node.get_left
                	elseif(check_right.get_value.is_greater(check_left.get_value))then
                		smallNode := used_node.get_right
                	else
                		smallNode := used_node
                	end

                	if attached tmpNode as check_tmp then
                		if (check_tmp.is_equal(used_node)) then --Put value in place of Node to be deleted --> "removed"
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
		end


feature --"Public" Delete-Method, redirects to deleteRec and prints result of it on the console; prohibites to delete the root
		-- Method uses a local variable : root_value containts the int-value of the tree-root

	delete(new_value : G)
		do
			if attached Current.get_root as check_root then
				delete_node := has_rec(new_value, check_root)
				root_value := check_root.get_value
			end

			if attached root_value as checked_root then
				if not checked_root.is_equal(new_value) then
					if attached delete_node as checked_delnode then
						-- has_rec returnt a Node
						--print("Value can be deleted")
						deleteRec(new_value, checked_delnode)
						print("Value has been deleted")
					else
						-- has_rec returnt Void
						print("Value does not exist in the given tree")
					end
				else
					print("You try to delete the root of this tree, this is not allowed")
				end
			end

			ensure then
			--	root_not_deleted : has_rec(root_value, root)

		end

feature -- public Method to check if a value is in a tree; returns true if value is found

	has(new_value : G): BOOLEAN
		require else
			valid_value : new_value /= Void
		Local
			found : BOOLEAN
		do
			if attached Current.get_root as check_root then
				first_node := has_rec(new_value, check_root)
			end

			if first_node = Void then
				-- if has_rec returns a Void-Object, the value has not been found
				found := false
			else
				-- if has_rec returns a not-Void Object, the value has been found
				found := true
			end
		Result := found
		ensure then
			valid_result : Result = true or Result = false
		end

feature{GENERICTREE} -- "private" has(), indicated by Exportation to class NONE, searches for the given Node in a tree
					-- if Node has been found, result is the found Node with the given value
					-- if a Node with given value can not be found , result is Void

	has_rec(new_value : G ; used_node : NODE[G]) : detachable NODE[G]
		require else
			valid_value : new_value /= Void
			valid_node : used_node /= Void
		do
			if new_value.is_equal(used_node.get_value) then --Value has been found, return Node
				Result := used_node
			end

			--Search on the left side
			if new_value.is_less(used_node.get_value) then
				if attached used_node.get_left as check_left then -- x /= Void, continue with check_
					Result := has_rec(new_value, check_left)
				else -- x = Void -> No more Nodes -> Value does not exist
					Result := Void
				end
			end

			--Search on the right side
			if new_value.is_greater(used_node.get_value) then --Be careful here
				if attached used_node.get_right as check_right then
					Result := has_rec(new_value, check_right)
				else
					Result := Void
				end
			end
		end

--feature -- Gets the height of Tree

	--get_height: INTEGER
	--Local
		--tmpReturn : INTEGER
	--	tmpReturn1 : INTEGER
	--	tmpReturn2 : INTEGER
--	do
	--	if attached root as ok_root then
		--	if attached root_value as check_rv then
			--	if attached ok_root.get_right as check_rr then

			--		tmpReturn1:= check_rv.max(check_)+1
					-- tmpReturn1:= tmpreturn1 +1
			--		if attached ok_root.get_left as check_rl then
				--		tmpReturn2:= check_rv.max(check_rl.get_height)+1
				--	end
		--		end
		--	else
		--		Result:=0
		--	end
		--	if tmpReturn1 > tmpReturn2 then
		--		tmpReturn := tmpReturn1
		--	elseif tmpReturn2 >= tmpReturn1  then
		--		tmpReturn := tmpReturn2
		--	end
		--	Result:= tmpReturn
	--	end
--	end

	--get_height(act_node : NODE[G]) : INTEGER
	--do
		--if act_node = Void then
			--Result := 0
		--else
			--if attached act_node.get_left as ok_left and attached act_node.get_right as ok_right then
				--Result := max(get_height (ok_left.get_value), get_height (act_node.get_right.get_value))
			--end
		--end
	--end


	--max(ok_a : G ; ok_b : G) : G
	--Local
		--res : NODE[G]
	--do
		--if ok_a < ok_b then
			--res := ok_b
		--else
			--res := ok_a
		--end
		--Result := res
	--end

end -- end of generic tree
