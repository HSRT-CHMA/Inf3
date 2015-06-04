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
		Current.updateheights(False)
		Current.updatebalance(False)
		if attached get_left as check_gl then
			if attached get_right as check_gr then
				from
			until
				Current.balance < -1 or Current.balance > 1
			loop
				if Current.balance > 1 then
					if Current.first_node.get_left.balance < 0 then
                    	Current.first_node.get_left.rotateleft
                    	Current.updateheights(True)
                    	Current.updatebalance(True)
                    end
                	Current.rotateright
                	Current.updateheights(True)
                	Current.updatebalance(True)
				end
            	if Current.balance < -1 then
            		if Current.first_node.get_right.balance > 0 then
            			Current.first_node.get_right.rotateright
                    	Current.updateheights(True)
                    	Current.updatebalance(True)
            		end
            		Current.rotateleft
                	Current.updateheights(True)
                	Current.updatebalance(True)
            	end
            end
		end

	end

feature -- Rotate Right Node

	rotateright
	Local
		A : detachable NODE[G]
		B : detachable NODE[G]
		T : detachable NODE[G]
	do
		A := Current.first_node
        B := Current.first_node.get_left.first_node
        T := B.get_right.first_node

        first_node := B
        B.get_right.first_node := A
        A.get_left.first_node := T
	end

feature -- Rotate Left Node

	rotateleft
	Local
		A : detachable NODE[G]
		B : detachable NODE[G]
		T : detachable NODE[G]
	do
		A := Current.first_node
        B := Current.first_node.get_right.first_node
        T := B.get_left.first_node

        first_node := B
        B.get_left.first_node := A
        A.get_right.first_node := T
	end

feature -- Update heights

	updateheights(recurse : BOOLEAN)
	Local
		height1: INTEGER
		height2: INTEGER
	do
		if Current.first_node = Void then
            if recurse then
            	if attached get_left as check_gl then
            		if attached get_right as check_gr then
						if Current.first_node.get_left /= Void then
                    	Current.first_node.get_left.updateheights(True)
                	end
                	if Current.first_node.get_right /= Void then
                    	Current.first_node.get_right.updateheights(True)
                	end

            		height1 := first_node.max(Current.first_node.get_left.height)+1
                	height2 := first_node.max(Current.first_node.get_right.height)+1

                	if height1 > height2 then
						height := height1
					elseif height2 >= height1  then
						height := height2
					end

        		else
            		height := -1
            	end
            end
		end
	end

feature -- update balance

	updatebalance(recurse : BOOLEAN)
	do
		if Current.first_node = Void then
            if recurse then
            	if attached updatebalance(True) as check_ub then
            		if attached get_left as check_gl then
						if attached get_right as check_gr then
							if Current.first_node.get_left /= Void then
                    			Current.first_node.get_left.updatebalance
                			end
                			if Current.first_node.get_right /= Void then
                    			Current.first_node.get_right.updatebalance
                			end
							balance := Current.first_node.get_left.height - Current.first_node.get_right.height
						end
					end
            	end
        	else
            	balance := 0
            end
        end
	end

feature -- isleaf checks if node is leaf

	isleaf : BOOLEAN
	do
		if (Current.height = 0) then
	 		Result:= True
	 	else
	 		Result:= False
	 	end
	end

feature	-- isbalanced True if balanced

	isbalanced : BOOLEAN
	Local
		tmp : BOOLEAN
	do
		if Current = Void or Current.first_node = Void then
			tmp := True
		else
			if attached first_node.get_left as check_gl then
				if attached first_node.get_right as check_gr then
					Current.updateheights (True)
					Current.updatebalance (True)
					tmp:=(Current.balance < 2 ) and Current.first_node.get_left.isbalanced and Current.first_node.get_right.isbalanced
				end
			end
		end
		Result:=tmp
	end

feature -- smallestnode of Tree

	smallestnode(node: NODE [G]) : detachable NODE[G]
	Local
		tmp: detachable NODE[G]
	do
		if attached first_node.get_left as check_gl then
			if attached first_node.get_right as check_gr then
				first_node:= first_node.get_right.first_node
				if first_node /= Void then
					tmp:= first_node
					from
					until
						first_node.get_left /= Void
					loop
						if first_node.get_left.first_node then
							tmp:=first_node
						else
							first_node:= first_node.get_left.first_node
						end
					end
				end
			end
		end
		Result:= tmp
	end

feature -- biggestnode of Tree

	biggestnode(node : NODE[G]) : detachable NODE[G]
	Local
		tmp: detachable NODE[G]
	do
		if attached first_node.get_left as check_gl then
			if attached first_node as check_fn then
				if attached first_node.get_right as check_gr then
					first_node:= first_node.get_left.first_node
					if first_node /= Void then
						tmp:= first_node
						from
						until
							first_node.get_right /= Void
						loop
							if first_node.get_right.first_node then
								tmp:=first_node
							else
								first_node:= first_node.get_right.first_node
							end
						end
					end
				end
			end
		end
		Result:= tmp
	end

end -- Class end


