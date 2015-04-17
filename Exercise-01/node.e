note
	description: "Summary description for {NODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	NODE

create
	make

feature --Variables

	value : INTEGER
	--Value of the given node
	left : NODE
	-- The left child of a node
	right : NODE
	--The rigth child of a node
	parent : NODE
	--The parent-node of the node


feature {NONE} --Initialization/Constructor

	make

	 do

	 	create n

	 end


feature --Access

	n : NODE


end
