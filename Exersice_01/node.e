note
	description: "Summary description for {NODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	NODE

create
	make

feature {BINARYTREE} -- Initialization

	make(node_value : INTEGER ; node_parent : NODE)
			-- Initialization for `Current'.
		do
			print ("New Node with value : " + node_value.out)
			set_value(node_value)
			set_parent(node_parent)
		end

feature --Variables

	value : INTEGER
	--Value of the given node; is initialised with default value
	left : detachable NODE
	-- The left child of a node; can be Void when left child does not exist
	right : detachable NODE
	--The right child of a node; can be Void when right child does not exist
	parent : detachable NODE
	--The parent-node of the node; can be Void when only root exist

feature{BINARYTREE} --Getter/Setter value
	get_value : INTEGER
	do
		Result := value
	end

	set_value(node_value : INTEGER)
	do
		value := node_value
	end

feature{BINARYTREE} --Getter/Setter left	
	get_left : NODE
	do
		Result := left
	end

	set_left(node_left : NODE)
	do
		left := node_left
	end

feature{BINARYTREE} --Getter/Setter rigth	
	get_right : NODE
	do
		Result := right
	end

	set_right(node_right : NODE)
	do
		right := node_right
	end

feature{BINARYTREE} --Getter/Setter parent
	get_parent : NODE
	do
		Result := parent
	end

	set_parent(node_parent : NODE)
	do
		parent := node_parent
	end


end
