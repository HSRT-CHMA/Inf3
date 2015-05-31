note
	description: "Summary description for {NODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	NODE
	-- This class organises the Node-Objects of a binary tree

create
	make

feature {BINARYTREE} -- Initialization/ Constructor ; sets the given node-value and the given parent-node

	make(node_value : INTEGER ; node_parent : detachable NODE)
			-- Initialization for `Current'.
		do
			set_value(node_value)
			set_parent(node_parent)
		end

feature --Access

	value : INTEGER
	--Value of the given node; is initialised with default value
	left : detachable NODE
	-- The left child of a node; can be Void when left child does not exist
	right : detachable NODE
	--The right child of a node; can be Void when right child does not exist
	parent : detachable NODE
	--The parent-node of the node; can be Void when only root exist

feature -- public Getter for value of the node
	get_value : INTEGER
	do
		Result := value
		ensure
			correct_value : Result = value
	end

feature{BINARYTREE} -- Setter for value of the node; only visible to its tree
	set_value(node_value : INTEGER)
	do
		value := node_value
		ensure
			correct_value : value = node_value
	end

feature --public Getter for left-node	
	get_left : detachable NODE
	do
		Result := left
		ensure
			correct_result : Result = left
	end

feature{BINARYTREE} -- Setter for the left-node, only visible to its tree
	set_left(node_left : detachable NODE)
	do
		left := node_left
		ensure
			correct_value : left = node_left
	end

feature --public Getter for the right-node	
	get_right : detachable NODE
	do
		Result := right
		ensure
			correct_result : Result = right
	end

feature{BINARYTREE} --Setter for right-node
	set_right(node_right : detachable NODE)
	do
		right := node_right
		ensure
			correct_value : right = node_right
	end

feature --public Getter for parent-node
	get_parent : detachable NODE
	do
		Result := parent
		ensure
			correct_result : Result = parent
	end

feature{BINARYTREE} --Setter for parent-node ; only visible to its tree

	set_parent(node_parent : detachable NODE)
	do
		parent := node_parent
		ensure
			correct_value : parent = node_parent
	end

invariant
	valid_value : value.abs >= 0
	-- if the absolut value is greater or equal than zero; the value is valid

end
