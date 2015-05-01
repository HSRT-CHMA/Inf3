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


feature{BINARYTREE} -- Delete-Method Sub

	deleteRec(new_value : INTEGER)
		do
			print("Delete- Function")
		end

feature --"Public" Delete-Method

	delete(new_value : INTEGER)
		do
			--if has(new_value) then
				--print("Value can be deleted")
			--else
				--print("Value can not be deleted")
			--end
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
