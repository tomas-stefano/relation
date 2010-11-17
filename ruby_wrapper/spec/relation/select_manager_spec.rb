require 'spec_helper'

module Relation
  describe SelectManager do
    let(:people) { Relation::Table.new('people') }
    
    describe '#select' do
      let(:manager) { SelectManager.new(people) }
      
      it "should pass a string" do
        manager.select("name")
        manager.to_sql.should == "SELECT name FROM users"
      end
      
      it "should pass many selects" do
        manager.select('name').select('email')
        manager.to_sql.should == "SELECT email,name FROM users"
      end
      
      it "should pass an array of selects" do
        manager.select('name', 'email', 'age')
        manager.to_sql.should == "SELECT age,email,name FROM users"
      end
    end
  
    describe '.superclass' do
      it "should be the class TreeManager" do
        SelectManager.superclass.should equal TreeManager
      end
    end
  end
end