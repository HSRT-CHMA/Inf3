note
	description: "Summary description for {NODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	NODE [G] --Generic typ
	-- This class organises the Node-Objects of a binary tree

create
	make

feature {GENERICTREE} -- Initialization/ Constructor ; sets the given node-value and the given parent-node

	make(node_value : G ; node_parent : detachable NODE[G])
			-- Initialization for `Current'.
		do
			set_value(node_value)
			set_parent(node_parent)
		end

feature --Access

	value : G
	--Generic type G
	--Value of the given node; is initialised with default value
	left : detachable NODE[G]
	-- The left child of a node; can be Void when left child does not exist
	right : detachable NODE[G]
	--The right child of a node; can be Void when right child does not exist
	parent : detachable NODE[G]
	--The parent-node of the node; can be Void when only root exist
	balance: INTEGER
	-- Int value for balancing


feature -- public Getter for value of the node
	get_value : G
	do
		Result := value
		ensure
			--correct_value : Result = value
	end

feature{GENERICTREE} -- Setter for value of the node; only visible to its tree
	set_value(node_value : G)
	do
		value := node_value
		ensure
			--correct_value : value = node_value
			-- Bitte überprüfen , Marco
	end

feature --public Getter for left-node	
	get_left : detachable NODE[G]
	do
		Result := left
		ensure
			correct_result : Result = left
	end

feature{GENERICTREE} -- Setter for the left-node, only visible to its tree
	set_left(node_left : detachable NODE[G])
	do
		left := node_left
		ensure
			correct_value : left = node_left
	end

feature --public Getter for the right-node	
	get_right : detachable NODE[G]
	do
		Result := right
		ensure
			correct_result : Result = right
	end

feature{GENERICTREE} --Setter for right-node
	set_right(node_right : detachable NODE[G])
	do
		right := node_right
		ensure
			correct_value : right = node_right
	end

feature --public Getter for parent-node
	get_parent : detachable NODE[G]
	do
		Result := parent
		ensure
			correct_result : Result = parent
	end

feature{GENERICTREE} --Setter for parent-node ; only visible to its tree

	set_parent(node_parent : detachable NODE[G])
	do
		parent := node_parent
		ensure
			correct_value : parent = node_parent
	end

feature{AVLTREE} -- for AVL Tree

	get_balance :detachable INTEGER
		do
			Result := balance
			ensure
			Result_is_set: Result = balance
		end

	set_balance(new_balance:detachable INTEGER)
		do
			balance := new_balance
		end

invariant
	valid_value : value /= Void

end -- class end of Node

