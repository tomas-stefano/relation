require 'spec_helper'

module Relation
  describe SelectManager do
    let(:people) { Relation::Table.new('people') }
    
    describe '#select' do
      it "should pass a string" do
        manager = SelectManager.new(people)
        manager.select("name")
        manager.to_sql.should == "SELECT name FROM users"
      end
    end
  end
end