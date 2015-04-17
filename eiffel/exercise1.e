note
	description: "Summary description for {EXERCISE1}: First Exercise in Eiffel"
	author: "inf3"
	date: "$Date$"
	revision: "$Revision$"

class
	EXERCISE1
--inherit
--	ARGUMENTS
create
	make
feature
	make
			-- Run application.
		do
			my_word := "Hello World!"
			my_word.mirror
			print (my_word)
		end
	my_word: STRING
end
