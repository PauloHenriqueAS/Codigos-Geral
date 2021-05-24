package com.github.PauloHenriqueAS.citis_api.states.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import com.github.PauloHenriqueAS.citis_api.states.State;

public interface StateRepository extends JpaRepository<State, Long> {
}
