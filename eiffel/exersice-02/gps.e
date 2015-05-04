note
	description: "Summary description for {GPS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	GPS

create
	make

feature {NONE} -- Initialization

	make(used_tree : BINARYTREE)
			-- Initialization for `Current'.
		do
			print("%NNew GPS !")
		end

end
