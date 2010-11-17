require 'spec_helper'

module Relation
  describe Table do
    let(:users) { Table.new('users') }
    let(:developers) { Table.new('developers') }
    
    describe '#name' do
      it "should return the name of the table" do
        users.name.should == "users"
      end
      it "should return the table name" do
        developers.name.should == "developers"
      end
    end
    
    describe '#select' do
      
      it "should be possible to pass String" do
        users.select("*").to_sql.should == "SELECT * FROM users"
      end
      
      it "should be possible to pass projections in a chain methods" do
        users.select("name").select("email").to_sql.should == "SELECT email,name FROM users"
      end
      
    end
    
    describe '#limit' do
      it "should add a limit number" do
        users.limit(1).to_sql.should == "SELECT FROM users LIMIT 1"
      end
      it "should add a high limit number" do
        users.limit(10_000_000_000).to_sql.should == "SELECT FROM users LIMIT 10000000000"
      end
    end
    
  end
end