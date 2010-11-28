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
      it "should return the table name of a long table" do
        table = Table.new("who_wants_to_live_forever_who_dares_to_love_forever")
        table.name.should == "who_wants_to_live_forever_who_dares_to_love_forever"
      end
    end
    
    describe '#select' do
      
      it "should be possible to pass String" do
        users.select("*").to_sql.should == "SELECT * FROM users"
      end
      
      it "should be possible to pass projections in a chain methods" do
        users.select("name").select("email").to_sql.should == "SELECT name,email FROM users"
      end
      
      it "should be possible to pass a SqlLiteral" do
        users.select(Relation::Nodes::SqlLiteral.new('name')).to_sql.should == "SELECT name FROM users"
      end
      
    end
    
    describe '#limit' do
      it "should add a limit number" do
        users.limit(1).to_sql.should == "SELECT FROM users LIMIT 1"
      end
      it "should add a high limit number" do
        pending
        users.limit(10_000_000_000).to_sql.should == "SELECT FROM users LIMIT 10000000000"
      end
    end
    
    describe '#where' do
      
      it "should return a tree manager" do
        users.where("login = 'tomas'").to_sql.should == "SELECT FROM users WHERE login = 'tomas'"
      end
      
      it "should return a tree manager" do
        manager = developers.where("id > 1")
        manager.select('name').to_sql.should == "SELECT name FROM developers WHERE id > 1"
      end
      
    end

    describe '#order' do
      it "should take a order" do
        users.order('name').to_sql.should == "SELECT FROM users ORDER BY name"        
      end
    end
    
    describe '#offset' do
      it "should add a offset" do
        developers.offset(100).to_sql.should == "SELECT FROM developers OFFSET 100"
      end
    end

    describe '#group' do
      it "should create a group" do
        developers.select('name').group('name').to_sql.should == "SELECT name FROM developers GROUP BY name"
      end
      it "should pass many groups" do
        users.group('name').group('email').to_sql.should == "SELECT FROM users GROUP BY name,email"
      end
    end

    describe '#having' do
      it "should add a having clause" do
        users.having('age > 10').to_sql.should == "SELECT FROM users HAVING age > 10"
      end
    end

    describe 'putting_all_together' do
      it "should pass limit before select" do
        users.limit(10).select('name').to_sql.should == "SELECT name FROM users LIMIT 10"
      end
      it "should pass select before limit" do
        users.select('email').limit(9999999).to_sql.should == "SELECT email FROM users LIMIT 9999999"
      end
    end
    
  end
end