require 'spec_helper'

module Relation
  module Nodes
    describe SqlLiteral do
      describe 'sql literal' do
        it "should create a sql literal" do
          SqlLiteral.new('*').should be_kind_of(Relation::Nodes::SqlLiteral)
        end
      end
    end
  end
end