package zephylix;

import java.util.List;
import java.util.Map;
public class LoxClass {
    final String name;

    LoxClass (String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }
}
