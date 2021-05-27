package Trabalho2;
import java.io.Serializable;
import java.time.LocalDate;

public class Funcionarios extends Pessoa implements PrintDados, Serializable{
	protected final LocalDate dataIngresso;
	protected String cargo;
	protected static double salarioBase;
	protected int idFuncionario;
	private static int nextID = 1;
	
	public Funcionarios () {
		this.dataIngresso = LocalDate.now();
	}

	public Funcionarios(String nome, String cpf, String email, String sexo, String cargo, double salBase) {
		super(nome, cpf, email, sexo);
		this.dataIngresso = LocalDate.now();
		setCargo(cargo);
		setSalarioBase(salBase);
		setIdFuncionario();
	}
	
	public LocalDate getDataIngresso() {
		return dataIngresso;
	}
	
	public String getCargo() {
		return cargo;
	}
	public boolean setCargo(String cargo) {
		if(cargo.length() > 0) {
			this.cargo = cargo;
			return true;
		}else {
			return false;
		}
	}
	public double getSalarioBase() {
		return salarioBase;
	}
	public boolean setSalarioBase(double salarioBase) {
		if(salarioBase >= 0) {
			this.salarioBase = salarioBase;
			return true;
		}else {
			return false;
		}
	}
	public int getIdFuncionario() {
		return idFuncionario;
	}
	public void setIdFuncionario() {
		this.idFuncionario = nextID + 1;
		nextID++;
	}
	
	public double calculaSalarioFinal() {
		return getSalarioBase();
	}
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Data Ingresso: " + getDataIngresso());
		System.out.println("Cargo: " + getCargo());
		System.out.println("Salário Base: " + getSalarioBase());
		System.out.println("Id Funcionário: " + getIdFuncionario());
	}
	
}
