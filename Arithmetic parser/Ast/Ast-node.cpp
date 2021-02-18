#include "Ast-node.h"


AstNode::AstNode(std::shared_ptr<Token> token): m_token(token) {}

AstNode::AstNode(std::shared_ptr<Token> token, std::shared_ptr<AstNode> left): m_token(token), m_left(left){}

AstNode::AstNode(std::shared_ptr<Token> token, std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right): m_token(token), m_left(left), m_right(right) {}

const std::shared_ptr<AstNode> AstNode::getRight() {
    return m_right;
}

const std::shared_ptr<AstNode> AstNode::getLeft() {
    return m_left;
}

const std::shared_ptr<Token> AstNode::getToken() {
    return m_token;
}
