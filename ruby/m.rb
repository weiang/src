module FirstModule
	def say
		puts "Hello"
	end
end

class ModuleTest
	include FirstModule
end

a = ModuleTest.new
a.say
