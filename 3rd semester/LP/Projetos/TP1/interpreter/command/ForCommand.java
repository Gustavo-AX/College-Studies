package interpreter.command;

import java.util.List;
import java.util.Map;

import interpreter.InterpreterException;
import interpreter.expr.Expr;
import interpreter.value.ListValue;
import interpreter.value.ObjectValue;
import interpreter.value.TextValue;
import interpreter.value.Value;
import interpreter.expr.Variable;

public class ForCommand extends Command {

    private Expr expr;
    private Command cmds;
    private Variable var;

    public ForCommand(int line, Expr expr, Command cmds, Variable var) {
        super(line);
        this.expr = expr;
        this.cmds = cmds;
        this.var = var;
    }

    @Override
    public void execute() {
        Value<?> v = expr.expr();
        //int a = (int) NumberValue.convert(var.expr());

        if (v instanceof ListValue) {
            ListValue lv = (ListValue) v;
            List<Value<?>> value = lv.value();

            for (int i = 0; i < value.size(); i++) {
                //a = (int) NumberValue.convert(value.get(i));
                //var.setValue(new NumberValue((double) a));
                var.setValue(value.get(i));
                cmds.execute();
            }

        } else if (v instanceof ObjectValue) {
            ObjectValue ov = (ObjectValue) v;
            Map<TextValue, Value<?>> value = ov.value();
           
            for(TextValue key: value.keySet()){
                var.setValue(key);
                cmds.execute();
            }
            
        } else {
            throw new InterpreterException(super.getLine());
        }

    }
}
