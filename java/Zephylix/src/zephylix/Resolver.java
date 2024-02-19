package zephylix;

import java.util.HashMap;
import java.util.List;
import java.util.Stack;
import java.util.Map;

public class Resolver implements Expr.Visitor<Void>,Stmt.Visitor {
    private final Interpreter interpreter;

    Resolver(Interpreter interpreter){
        this.interpreter = interpreter;
    }
}
