package Trabalho2;
import java.time.LocalDate;

public class Funcionarios extends Pessoa{
	protected final LocalDate dataIngresso;
	protected String cargo;
	protected double salarioBase;
	protected int idFuncionario;
	private static int nextID = 1;
	
	public Funcionarios () {
		this.dataIngresso = LocalDate.now();
	}

	public Funcionarios(String nome, String cpf, String email, String sexo, String cargo, double salBase) {
		super(nome, cpf, email, sexo);
		this.dataIngresso = LocalDate.now();//TODO rever com a prof
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
	
	/*Metodos
	public void cadastrarFuncionario(String nome, String tel1, String cpf, String endereco, String telContato, String TelCell, LocalDate dataIngresso, String cargo, double salarioBase){}
	public double consultarSalario(String cpf){	}*/

}
