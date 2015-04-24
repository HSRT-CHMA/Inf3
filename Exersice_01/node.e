note
	description: "Summary description for {NODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	NODE

create
	make

feature {NONE} -- Initialization

	make(node_value : INTEGER)
			-- Initialization for `Current'.
		do
			print ("New Node with value : " + node_value.out)
			set_value(node_value)
		end

feature --Variables

	value : INTEGER
	--Value of the given node
	left : NODE
	-- The left child of a node
	right : NODE
	--The right child of a node
	parent : NODE
	--The parent-node of the node
	number_of_children : INTEGER

feature --Getter/Setter value
	get_value : INTEGER
	do
		Result := value
	end

	set_value(node_value : INTEGER)
	do
		value := node_value
	end

feature --Getter/Setter left	
	get_left : NODE
	do
		Result := left
	end

	set_left(node_left : NODE)
	do
		left := node_left
	end

feature --Getter/Setter rigth	
	get_right : NODE
	do
		Result := right
	end

	set_right(node_right : NODE)
	do
		right := node_right
	end

feature --Getter/Setter parent
	get_parent : NODE
	do
		Result := parent
	end

	set_parent(node_parent : NODE)
	do
		parent := node_parent
	end


end
