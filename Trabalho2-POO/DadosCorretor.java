package Trabalho2;

import java.util.ArrayList;

public class DadosCorretor {
	private ArrayList<Corretor> vetCorretor = new ArrayList<Corretor>();
	
	public void cadastrar(Corretor c) {
		this.vetCorretor.add(c);
		Persist.salvarBinario("corretor.dat", c);//Salvar no arquivo
		System.out.println("Total de Corretors inseridas: ");
		System.out.println(this.vetCorretor.size());
	}
	
	public void listar(){
		for (Corretor objeto: this.vetCorretor) {
			objeto.mostarDados();
		}
	}
	
	public Corretor buscar(String nome) {
		Corretor c = null;
		for ( Corretor objeto: this.vetCorretor) {
			if (objeto.getNome().equals(nome)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String nome){
		Corretor CorretorRemove = this.buscar(nome);
		
		if(CorretorRemove != null) {
			this.vetCorretor.remove(CorretorRemove);
			return true;
		}else {
			return false;
		}
	}
}
