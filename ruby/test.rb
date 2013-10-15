#! /usr/bin/env ruby
require "./project.rb"
class Manager
	include Project
end

test = Manager.new
test.add("jack")
test.add("weiang")
p test.members
test.remove
p test.members
