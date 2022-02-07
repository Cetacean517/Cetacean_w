import javax.swing.table.TableCellEditor;

interface Manageable {
// 提供学位管理功能

    public abstract double computeAverage() throws Exception;
    public abstract boolean getPass() throws Exception;
    public abstract void printInfo() throws Exception;
}
