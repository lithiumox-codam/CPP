import { $ } from 'bun'

export type testFunction = () => Promise<Boolean>

export async function tester(name: string, test: testFunction): Promise<void> {
    try {
        await test()
    } catch (e) {
        console.error(`Test ${name} failed with error:`)
        console.error(e)

    } finally {
        console.log(`Test ${name} finished successfully!`)
    }
}
