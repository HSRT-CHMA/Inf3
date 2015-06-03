note
	description: "Summary description for {MAINTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	MAINTREE[G]

feature -- Defered Methods to be overriden in subclasses

	insert(item : G) -- Insert - Methode is deferred, contains no implementation
	deferred
	end

	has(item : G) : BOOLEAN
	deferred
	end

	delete(item : G)
	deferred
	end



feature --Access

	--item : G
	-- not detachable ?

end
