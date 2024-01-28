import { $ } from 'bun'
import { tester } from './tester'
import { ex00 } from './modules/00'

await $`make -C ../`.quiet()

await tester("00/ex00", ex00)
