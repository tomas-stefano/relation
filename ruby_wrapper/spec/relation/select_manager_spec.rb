require 'spec_helper'

module Relation
  describe SelectManager do
    let(:people) { Relation::Table.new('people') }
    let(:manager) { SelectManager.new(people) }
    
    describe '#select' do

      it "should pass a string" do
        manager.select("name")
        manager.to_sql.should == "SELECT name FROM people"
      end
      
      it "should pass many selects" do
        manager.select('name').select('email')
        manager.to_sql.should == "SELECT email,name FROM people"
      end
      
      it "should pass an array of selects" do
        manager.select('name', 'email', 'age')
        manager.to_sql.should == "SELECT age,email,name FROM people"
      end
    end
  
    describe '#limit' do
      it "should pass a limit number" do
        manager.limit(10).to_sql.should == "SELECT FROM people LIMIT 10"
      end
    end
    
    describe '.superclass' do
      it "should be the class TreeManager" do
        SelectManager.superclass.should equal TreeManager
      end
    end
  
  end
end