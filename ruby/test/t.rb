class Customer
	def initialize(firstname, lastname)
		@first_name = firstname
		@last_name = lastname
	end

	def add_name(file)
		file << @first_name << " " << @last_name
	end
end


require 'test/unit'
class TestAddCus < Test::Unit::TestCase
	def test
		c = Customer.new('wei', 'ang')
		File.open("tmpfile", "w") do |f|
			c.add_name(f)
		end
		File.open("tmpfile") do |f|
			assert_equal("wei ang", f.gets)
		end
	ensure
#		File.delete("tmpfile") if File.exist?("tmpfile")
	end
end

class T < Test::Unit::TestCase
	def t
		c = Customer.new('wei', 'ang')
		f = ''
		c.add_name(f)
		assert_equal('wei ang', f)
	end
end

