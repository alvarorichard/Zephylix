package zephylix;

import java.util.HashMap;
import java.util.List;
import java.util.Stack;
import java.util.Map;

public class Resolver implements Expr.Visitor<Void>,Stmt.Visitor {
    private final Interpreter interpreter;

    private final Stack<Map<String, Boolean>> scopes = new Stack<>();

    Resolver(Interpreter interpreter){
        this.interpreter = interpreter;
    }

    @Override
    public Void visitBlockStmt(Stmt.Block stmt){
        beginScope();
        resolve(stmt.statements);
        endScope();
        return null;
    }

    void resolve(List<Stmt> statements){
        for (Stmt statement : statements){
            resolve(statement);
        }
    }
    private void resolve(Stmt statement){
        stmt.accept(this);
    }

    private  void resolve(Expr expr){
        expr.accept(this);
    }

    private void beginScope(){
        scopes.push(new HashMap<String, Boolean>());
    }

    private void endScope(){
        scopes.pop();
    }

    @Override
    public Void visitVarStmt(Stmt.Var stmt){
        declare(stmt.name);
        if (stmt.initializer != null){
            resolve(stmt.initializer);
        }
        define(stmt.name);
        return null;
    }

    private void declare(Token name){
        if (scopes.isEmpty()) return;
        Map<String, Boolean> scope = scopes.peek();
        if (scope.containsKey(name.lexeme)){
            lox.error(name, "Variable with this name already declared in this scope.");
        }
        scope.put(name.lexeme, false);
    }

    


}
