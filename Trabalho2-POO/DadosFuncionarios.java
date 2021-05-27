package Trabalho2;

import java.util.ArrayList;

public class DadosFuncionarios {
	private ArrayList<Funcionarios> vetFuncionarios = new ArrayList<Funcionarios>();
	
	public void cadastrar(Funcionarios c) {
		this.vetFuncionarios.add(c);
		Persist.salvarBinario("funcionarios.dat", c);//Salvar no arquivo
		System.out.println("Total de funcionarios inseridos: ");
		System.out.println(this.vetFuncionarios.size());
	}
	
	public void listar(){
		for (Funcionarios objeto: this.vetFuncionarios) {
			objeto.mostarDados();
		}
	}
	
	public Funcionarios buscar(String nome) {
		Funcionarios c = null;
		for ( Funcionarios objeto: this.vetFuncionarios) {
			if (objeto.getNome().equals(nome)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String nome){
		Funcionarios funcionariosRemove = this.buscar(nome);
		
		if(funcionariosRemove != null) {
			this.vetFuncionarios.remove(funcionariosRemove);
			return true;
		}else {
			return false;
		}
	}
}
