note
	description: "Summary description for {AVLTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	AVLTREE[G->COMPARABLE]

inherit
	GENERICTREE[G]
	redefine insert,delete,has end

create
	make

feature {NONE} -- Initialization / Constructor ; gets the value that serves as root-value

	make(tree_value : G)
		do
			print("%N A new AVL Tree has been created")
			create root.make(tree_value, Void)
		end

feature --Access
	balance : INTEGER
	-- Balance value
	height : INTEGER
	-- Height of Tree


feature -- Override of insert

	insert(new_value : G)
		do
			Precursor(new_value)
			Current.rebalance
		end


feature -- Override of delete

	delete(new_value : G)
		do
			Precursor(new_value)
			Current.rebalance
		end

feature -- Override of has

	has(new_value : G): BOOLEAN
		do
			Result := Precursor(new_value)
		end

feature -- rebalance tree

	rebalance
	do
		Current.updateHeights(False)
		Current.updateBalances(False)

		do
			until
				Current.balance < -1 or Current.balance > 1
			loop
				if Current.balance > 1 then
					if Current.first_node.get_left.balance < 0 then
                    	Current.first_node.get_left.rotateLeft()
                    	Current.updateHeights()
                    	Current.updateBalances()
                    end
                	Current.rotateRight()
                	Current.updateHeights()
                	Current.updateBalances()
				end
            	if Current.balance < -1 then
            		if Current.first_node.get_right.balance > 0 then
            			Current.first_node.get_right.rotateRight()
                    	Current.updateHeights()
                    	Current.updateBalances()
            		end
            		Current.rotateLeft()
                	Current.updateHeights()
                	Current.updateBalances()
            	end
            end
		end
	end

feature -- Rotate Right Node

	rotateRight
	do
		A := Current.first_node
        B := Current.first_node.get_left.first_node
        T := B.get_right.first_node

        Current.node := B
        B.get_right.first_node := A
        A.get_left.first_node := T
	end

feature -- Rotate Left Node

	rotateLeft
	do
		A := Current.first_node
        B := Current.first_node.get_right.first_node
        T := B.get_left.first_node

        Current.node := B
        B.get_left.first_node := A
        A.get_right.first_node := T
	end

feature -- Update Heights

	updateHeights(recurse := True)
	Local
		height1: INTEGER
		height2: INTEGER
	do
		if not Current.first_node = Void then
            if recurse then
                if Current.first_node.get_left != Void then
                    Current.first_node.get_left.updateHeights()
                end
                if Current.first_node.get_right != Void then
                    Current.first_node.get_right.updateHeights()
                end

            	height1 := max(Current.first_node.get_left.height)+1
                height2 := max(Current.first_node.get_right.height)+1

                if height1 > height2 then
					Current.height := height1
				elseif height2 >= height1  then
					Current.height := height2
				end

        	else
            	Current.height := -1
            end
        end
	end

feature -- update Balance

	updateBalance(recurse := True)
	do
		if not Current.first_node = Void then
            if recurse then
                if Current.first_node.get_left != Void then
                    Current.first_node.get_left.updateBalance()
                end
                if Current.first_node.get_right != Void then
                    Current.first_node.get_right.updateBalance()
                end

				Current.balance := Current.first_node.get_left.height - Current.first_node.get_right.height

        	else
            	Current.balance := 0
            end
        end
	end

feature -- isleaf checks if node is leaf

	isLeaf : INTEGER
	do
		Result:= (Current.height = 0)
	end

end -- Class end








