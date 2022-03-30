package Domain;

import java.util.Date;

public class Emp {
    private int id;
    private String ename;
    private int job_id;
    private int mgr;
    private Date joindate;
    private Double salary;
    private Double bonus;
    private int dept_id;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getEname() {
        return ename;
    }

    public void setEname(String ename) {
        this.ename = ename;
    }

    public int getJob_id() {
        return job_id;
    }

    public void setJob_id(int job_id) {
        this.job_id = job_id;
    }

    public int getMgr(int mgr) {
        return this.mgr;
    }

    public void setMgr(int mgr) {
        this.mgr = mgr;
    }

    public Date getJoindate(java.sql.Date joindate) {
        return this.joindate;
    }

    public void setJoindate(Date joindate) {
        this.joindate = joindate;
    }

    public Double getSalary(double salary) {
        return this.salary;
    }

    public void setSalary(Double salary) {
        this.salary = salary;
    }

    public Double getBonus(double bonus) {
        return this.bonus;
    }

    public void setBonus(Double bonus) {
        this.bonus = bonus;
    }

    public int getDept_id(int dept_id) {
        return this.dept_id;
    }

    public void setDept_id(int dept_id) {
        this.dept_id = dept_id;
    }

    @Override
    public String toString() {
        return "Emp{" +
                "id=" + id +
                ", ename='" + ename + '\'' +
                ", job_id=" + job_id +
                ", mgr=" + mgr +
                ", joindate=" + joindate +
                ", salary=" + salary +
                ", bonus=" + bonus +
                ", dept_id=" + dept_id +
                '}';
    }
}
