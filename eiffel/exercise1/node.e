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

	make(node_value : INTEGER ; node_parent : detachable NODE)
			-- Initialization for `Current'.
		do
			print("%N New Node " + node_value.out)
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
	get_left : detachable NODE
	do
		Result := left
	end

	set_left(node_left : detachable NODE)
	do
		--if node_left /= Void then
			--left := node_left
		--else
			--left := Void
		--end
		left := node_left

	end

feature{BINARYTREE} --Getter/Setter rigth	
	get_right : detachable NODE
	do
		Result := right
	end

	set_right(node_right : detachable NODE)
	do
		if node_right /= Void then
			right := node_right
		else
			right := Void
		end

	end

feature{BINARYTREE} --Getter/Setter parent
	get_parent : detachable NODE
	do
		Result := parent
	end

	set_parent(node_parent : detachable NODE)
	do
		if node_parent /= Void then -- equal to attached node_parent
			parent := node_parent
		else
			parent := Void
		end
	end

end
