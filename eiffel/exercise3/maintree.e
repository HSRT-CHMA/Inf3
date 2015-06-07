note
	description: "Summary description for {MAINTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	MAINTREE[G]
	-- Maintree acts as Global Tree Class

feature -- Defered Methods to be overriden in subclasses

	insert(item : G) -- Insert - Methode is deferred, contains no implementation
	deferred
	end

	has(item : G) : BOOLEAN -- has - Methode is deferred, contains no implementation
	deferred
	end

	delete(item : G) -- delete - Methode is deferred, contains no implementation
	deferred
	end


end
