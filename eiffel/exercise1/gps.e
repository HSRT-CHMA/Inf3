note
	description: "Summary description for {GPS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	GPS

create
	make

feature{NONE} -- Initialization

	make(used_tree : BINARYTREE)
			-- Initialization for `Current'.
		do
			if attached used_tree.get_root as checked_root then
				print("%NNew GPS !")
			end

		end

end
