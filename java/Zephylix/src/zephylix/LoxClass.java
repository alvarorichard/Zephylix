package zephylix;

import java.util.List;
import java.util.Map;
import java.util.HashMap;

public class LoxClass implements LoxCallable {
    final String name;
    final LoxClass superclass;
    private final Map<String, LoxFunction> methods, staticMethods;

    LoxClass(String name, LoxClass superclass,
             Map<String, LoxFunction> methods) {
        this.superclass = superclass;
        this.name = name;
        this.methods = methods;
        this.staticMethods = staticMethods;
    }

    LoxFunction findMethod(LoxInstance instance, String name) {
        if (methods.containsKey(name)) {
            return methods.get(name);
        }
        if (staticMethods.containsKey(name)) {
            return staticMethods.get(name);
        }
        if (superclass != null) {
            return superclass.findMethod(instance, name);
        }
        return null;
    }



    @Override
    public String toString() {
        return name;
    }

    @Override
    public Object call(Interpreter interpreter, List<Object> arguments) {
        LoxInstance instance = new LoxInstance(this);
        LoxFunction initializer = findMethod("init");
        if (initializer != null) {
            initializer.bind(instance).call(interpreter, arguments);
        }
        return instance;
    }

    @Override
    public int arity() {
        LoxFunction initializer = findMethod("init");
        if (initializer == null) return 0;
        return initializer.arity();
    }
}
