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
	-- Gets created by a new tree, used in insert()- Method
	root : detachable NODE
	-- Becomes the root of the new tree
	b : BOOLEAN
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
			has_rec(new_value, check_root)
		end

		if get_res_node /= Void then
			--set_b(true)
			--b := true
			Result := true
		else -- x = Void
			--set_b(false)
			--b := false
			Result := false
		end
		--Result := get_b
		--Result := b
	end

feature{NONE} -- "private" has()

	has_rec(new_value : INTEGER ; used_node : NODE) : detachable NODE
	do
		if new_value = used_node.get_value then
			--set_b(true)
			--set_res_node(used_node) --Found
			Result := used_node
		end

		if new_value < used_node.get_value then
			if attached used_node.get_left as check_left then
				Result := has_rec(new_value, check_left)
			else -- x = Void -> No more Nodes -> Value does not exist
				--set_b(false)
				set_res_node(Void)
			end
		else
			if attached used_node.get_right as check_right then
				Result := has_rec(new_value, check_right)
			else
				--set_b(false)
				set_res_node(Void)
			end
		end
	end




feature --Getter/Setter boolean

	get_b : BOOLEAN
		do
			Result := b
		end

	set_b(new_b : BOOLEAN)
		do
			b := new_b
		end


feature --Getter/Setter res_node

	get_res_node : detachable NODE
		do
			Result := res_node
		end

	set_res_node(new_res_node : detachable NODE)
		do
			res_node := new_res_node
		end

end
